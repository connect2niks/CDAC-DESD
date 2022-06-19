# UTILITY

1. Write your own utility using system calls (open, read, write, close) to copy data from one file to another file. Essentially you are implementing a copy utility. Fullfledged utility should support the following options:

    - Handling all the errors
    - cp srcfile destfile

2. Write your own utility using library calls (fopen, fread, fwrite, fclose) to copy data from one file to another file. Essentially you are implementing a copy utility. Fullfledged utility should support the following options:

    - Handling all the errors
    - cp srcfile destfile

3. Research

    - Which of the following programs took more time to copy file
        1. Small
        2. Medium
        3. Large

4. Justify your results => Why does system call / library call take time to copy file.


![time](https://user-images.githubusercontent.com/105863377/171997015-97e68f8b-a9d7-4833-8f3d-7493d3f31444.png)




Justifying Results.

|   file size   |      cps      |    cpl    |
| ------------- |:-------------:| ---------:|
| 1 Mb file     | 0m0.203s      | 0m0.046s  |
| 400 Mb file   | 0m44.498s     | 0m12.535s |
| 1 Gb file     | 2m30.219s     | 0m54.450s |

- cpl is copy utility using library calls
- cps is copy utility using system calls
- Same buffer size used in above operation i.e 1Kb 
- The execution speed of the library calls is faster than the system calls.