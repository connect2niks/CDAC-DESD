#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void init_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(const char board[BOARD_SIZE][BOARD_SIZE]);
int parse_move(const char *input, int *fr, int *ff, int *tr, int *tf);
int is_valid_move(const char board[BOARD_SIZE][BOARD_SIZE],
                  int fr, int ff, int tr, int tf, int white_to_move);
int is_path_clear(const char board[BOARD_SIZE][BOARD_SIZE],
                  int fr, int ff, int tr, int tf);

int main(void)
{
    char board[BOARD_SIZE][BOARD_SIZE];
    char buffer[100];
    int fr, ff, tr, tf;
    int white_to_move = 1;

    init_board(board);

    while (1)
    {
        print_board(board);
        printf("%s to move. Enter move (e.g., e2e4) or 'quit': ",
               white_to_move ? "White" : "Black");

        if (!fgets(buffer, sizeof(buffer), stdin))
            break;

        if (buffer[0] == 'q') // simple quit check
            break;

        if (!parse_move(buffer, &fr, &ff, &tr, &tf))
        {
            printf("Invalid move format. Use like e2e4.\n");
            continue;
        }

        char piece = board[fr][ff];
        if (piece == '.')
        {
            printf("No piece at source square.\n");
            continue;
        }

        // Enforce side to move
        if (white_to_move && !isupper((unsigned char)piece))
        {
            printf("It's White's turn, move a white piece.\n");
            continue;
        }
        if (!white_to_move && !islower((unsigned char)piece))
        {
            printf("It's Black's turn, move a black piece.\n");
            continue;
        }

        if (!is_valid_move(board, fr, ff, tr, tf, white_to_move))
        {
            printf("Illegal move for that piece.\n");
            continue;
        }

        // Make the move
        board[tr][tf] = board[fr][ff];
        board[fr][ff] = '.';

        white_to_move = !white_to_move;
    }

    printf("Game over.\n");
    return 0;
}

void init_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    // Rank 1 (index 0) - White pieces
    board[0][0] = 'R'; board[0][1] = 'N'; board[0][2] = 'B'; board[0][3] = 'Q';
    board[0][4] = 'K'; board[0][5] = 'B'; board[0][6] = 'N'; board[0][7] = 'R';

    // Rank 2 (index 1) - White pawns
    for (int f = 0; f < BOARD_SIZE; f++)
        board[1][f] = 'P';

    // Ranks 3–6 (index 2–5) - empty
    for (int r = 2; r <= 5; r++)
        for (int f = 0; f < BOARD_SIZE; f++)
            board[r][f] = '.';

    // Rank 7 (index 6) - Black pawns
    for (int f = 0; f < BOARD_SIZE; f++)
        board[6][f] = 'p';

    // Rank 8 (index 7) - Black pieces
    board[7][0] = 'r'; board[7][1] = 'n'; board[7][2] = 'b'; board[7][3] = 'q';
    board[7][4] = 'k'; board[7][5] = 'b'; board[7][6] = 'n'; board[7][7] = 'r';
}

void print_board(const char board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n    a   b   c   d   e   f   g   h\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int r = BOARD_SIZE - 1; r >= 0; r--)
    {
        printf("%d |", r + 1);
        for (int f = 0; f < BOARD_SIZE; f++)
        {
            printf(" %c |", board[r][f]);
        }
        printf(" %d\n", r + 1);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    a   b   c   d   e   f   g   h\n\n");
}

// Parse "e2e4" into from_row, from_file, to_row, to_file
int parse_move(const char *input, int *fr, int *ff, int *tr, int *tf)
{
    // Expect exactly something like e2e4\n or e2e4\0
    if (!('a' <= input[0] && input[0] <= 'h')) return 0;
    if (!('1' <= input[1] && input[1] <= '8')) return 0;
    if (!('a' <= input[2] && input[2] <= 'h')) return 0;
    if (!('1' <= input[3] && input[3] <= '8')) return 0;

    *ff = input[0] - 'a';
    *fr = input[1] - '1';  // rank 1 -> index 0
    *tf = input[2] - 'a';
    *tr = input[3] - '1';

    if (*fr < 0 || *fr >= BOARD_SIZE ||
        *tr < 0 || *tr >= BOARD_SIZE ||
        *ff < 0 || *ff >= BOARD_SIZE ||
        *tf < 0 || *tf >= BOARD_SIZE)
        return 0;

    return 1;
}

int same_color(char a, char b)
{
    if (a == '.' || b == '.')
        return 0;
    return (isupper((unsigned char)a) && isupper((unsigned char)b)) ||
           (islower((unsigned char)a) && islower((unsigned char)b));
}

int is_valid_pawn_move(const char board[BOARD_SIZE][BOARD_SIZE],
                       int fr, int ff, int tr, int tf, int white_to_move)
{
    char piece = board[fr][ff];
    int dir = isupper((unsigned char)piece) ? 1 : -1;  // White goes up, Black down
    int start_rank = isupper((unsigned char)piece) ? 1 : 6;

    int dr = tr - fr;
    int df = tf - ff;

    char target = board[tr][tf];

    // Forward move (no capture)
    if (df == 0)
    {
        // One step
        if (dr == dir && target == '.')
            return 1;

        // Two steps from start
        if (fr == start_rank && dr == 2 * dir && target == '.' &&
            board[fr + dir][ff] == '.')
            return 1;

        return 0;
    }

    // Diagonal capture
    if (dr == dir && (df == 1 || df == -1))
    {
        if (target != '.' && !same_color(piece, target))
            return 1;
        return 0;
    }

    return 0;
}

int is_valid_knight_move(const char board[BOARD_SIZE][BOARD_SIZE],
                         int fr, int ff, int tr, int tf)
{
    int dr = abs(tr - fr);
    int df = abs(tf - ff);
    if ((dr == 2 && df == 1) || (dr == 1 && df == 2))
        return 1;
    return 0;
}

int is_valid_king_move(const char board[BOARD_SIZE][BOARD_SIZE],
                       int fr, int ff, int tr, int tf)
{
    int dr = abs(tr - fr);
    int df = abs(tf - ff);
    if (dr <= 1 && df <= 1)
        return 1;
    return 0;
}

int is_valid_move(const char board[BOARD_SIZE][BOARD_SIZE],
                  int fr, int ff, int tr, int tf, int white_to_move)
{
    if (fr == tr && ff == tf)
        return 0;

    char piece = board[fr][ff];
    char target = board[tr][tf];

    // Cannot capture own piece
    if (same_color(piece, target))
        return 0;

    int dr = tr - fr;
    int df = tf - ff;

    char lower = (char)tolower((unsigned char)piece);

    switch (lower)
    {
        case 'p':
            return is_valid_pawn_move(board, fr, ff, tr, tf, white_to_move);

        case 'n': // knight
            return is_valid_knight_move(board, fr, ff, tr, tf);

        case 'k': // king
            return is_valid_king_move(board, fr, ff, tr, tf);

        case 'b': // bishop
            if (abs(dr) == abs(df) && is_path_clear(board, fr, ff, tr, tf))
                return 1;
            return 0;

        case 'r': // rook
            if ((dr == 0 || df == 0) && is_path_clear(board, fr, ff, tr, tf))
                return 1;
            return 0;

        case 'q': // queen
            if (((dr == 0 || df == 0) || (abs(dr) == abs(df))) &&
                is_path_clear(board, fr, ff, tr, tf))
                return 1;
            return 0;

        default:
            return 0;
    }
}

// Check that squares between from and to are empty (for sliding pieces)
int is_path_clear(const char board[BOARD_SIZE][BOARD_SIZE],
                  int fr, int ff, int tr, int tf)
{
    int dr = (tr > fr) ? 1 : (tr < fr) ? -1 : 0;
    int df = (tf > ff) ? 1 : (tf < ff) ? -1 : 0;

    int r = fr + dr;
    int f = ff + df;

    while (r != tr || f != tf)
    {
        if (board[r][f] != '.')
            return 0;
        r += dr;
        f += df;
    }

    return 1;
}

