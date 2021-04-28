#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void alarmHandler();

int main(){

    // a. perror()********************************************
    //displays a description of the last system call error
    if("invalid argument"){ //should cause error
        //displays error
        perror("Error");
    }

    // b. open()**********************************************
    // used to open or create a file. If succeeds returns an integer called a file descriptor, 
    // if it fails it returns -1
    int f = open("./text.txt", O_RDONLY);
    (f != -1) ? printf("Open: success\n") : printf("Open: fail\n"); //test if file opened

    // c. read()***********************************************
    // low-level reading bytes from a file passed as a file descriptor integer into a 
    // buffer upto the specified number of bytes in count. Faster than scanf
    char buffer[32]; //8 byte buffer
    int numCharsRead = read(f, buffer, 30); // read first 4 bytes in file
    printf("Read: %d bytes -> %s", numCharsRead, buffer);

    // d. write*************************************************
    // low-level writing to file by copying bytes from a buffer to the file passed as 
    //a file descriptor integer. Bypasses C library and therefore faster than printf() 
    //but doesn’t have any of the formatting options
    //returns number of character written to file
    int f2 = open("./demo.txt", O_CREAT | O_APPEND | O_RDWR, 0755); //create new or open file called demo.txt to be written to
    int numCharsToWrite = strlen(buffer);
    int numCharsWritten = write(f2, buffer, numCharsToWrite);
    (numCharsToWrite == numCharsToWrite) ? printf("Write: Success\n") : printf("Write: Fail\n");

    // e. lseek()************************************************
    // changes the file position of the passed file. 
    // Returns -1 if you try to move beyond the scope of the file. 
    // Offset can be from beginning, current position, or end of file
    (lseek(f2, 1, SEEK_SET) != -1) ? printf("lseek: Success\n") : printf("lseek: Fail\n"); //expected: should succeed 

    // f. close() *see bottom of main() 

    // g. monitor *see answer sheet

    // h. chown()*************************************************
    // changes a files owner and group id to passed arguments 
    //returns -1 if failed
    // passing -1 means fields remain unchanged
    (chown("demo.txt", -1, -1) != -1) ? printf("chown: Success\n") : printf("chown: Fail\n"); //didn't want to change it

    // i. fchown()************************************************
    // same as chown but accepts file descriptor instead of file
    (fchown(f2, -1, -1) != -1) ? printf("fchown: Success\n") : printf("fchown: Fail\n"); //didn't want to change it

    // j. chmod()*************************************************
    // changes the mode or file permissions of passed file
    // returns -1 if failed
    (chmod("demo.txt", 0755) != -1) ? printf("chmod: Success\n") : printf("chmod: Fail\n"); 

    // k. fchmod()*************************************************
    // same as chown but accepts file descriptor instead of file
    (fchmod(f2, 0754) != -1) ? printf("fchmod: Success\n") : printf("fchmod: Fail\n");

    // l. link()***************************************************
    // creates a hard link between files
    (link("text.txt", "link.example") != -1) ? printf("link: Success\n") : printf("link: Fail\n");
    
    
    // m. unlink()
    // removes hardlink assoicated to file name. If there are no other links it deallocates file’s resources
    (unlink("link.example") != -1) ? printf("unlink: Success\n") : printf("unlink: Fail\n");

    // n. getpid()**************************************************
    // get process ID
    printf("pid: %d\n", getpid());

    // o. getppid()**************************************************
    // get parent process ID
    printf("ppid: %d\n", getppid());

    // p. fork()*****************************************************
    // duplicates a process
    // returns -1 if failed
    int forkId;
    ((forkId = fork()) != -1) ? printf("fork: Success\n") : printf("fork: Fail\n"); 

    // q. exit() *see bottom of file

    // r. wait()*****************************************************
    // waits for a child process to exit before continuing 
    int status;
    if(forkId != 0) {
        printf("Waiting for child to exit...\n");
        wait(&status);
    } else {
        printf("exiting child process...\n");
        exit(420);
    }

    // s. alarm()***************************************************
    // instructs kernal to send the SIGALARM signal to the calling processor after 
    // number of seconds passed as parameter
    signal(SIGALRM, alarmHandler); // for part t. 
    alarm(5);
    printf("Starting alarm for 5 seconds\n");
    sleep(10);
    //printf("This will never be reached\n"); //will be reached now with signal

    // t. signal()************************************************
    // waits for a specified signal then executes process passed as parameter
    printf("Signal: Success\n");

    // u. kill()*************************************************
    // sends specified signal to specified pid
    // name is misnomer since it doesn't necessarily kill a process itself
    printf("sending SIGALRM to this process\n");
    kill(getpid(), SIGALRM); //SIGALRM will be caught by alarmHandler

    // v. pipe()****************************************************
    // creates an unnamed pipe with a read end and a write end
    // returns 2 file descriptors one for each end of pipe
    int fd3[2];
    pipe(fd3);
    printf("Pipe created between: fd3[0](read): %d and fd3[1](write): %d\n", fd3[0], fd3[1]);
    close(fd3[0]);
    close(fd3[1]);

    //////////////////
    //end of file contents
    //////////////////

    // *f. close()**************************************************
    // closes the files that was opened by freeing the file descriptor
    close(f); 
    close(f2);

    // q. exit()*****************************************************
    //terminates process and returns a passed status code
    printf("exiting program...\n");
    exit(420);
    printf("test\n"); //never reached
    return 0;
}

void alarmHandler(){
    printf("Alarm caught\n");
}