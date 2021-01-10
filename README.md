# Get Next Line
Write a function which returns a line read from a file descriptor, without the newline.
```
int get_next_line(int fd, char **line);
```
#### Parameters
#1. file descriptor for reading

#2. The value of what has been read

#### Return value
1 : A line has been read

0 : EOF has been reached

-1 : An error happened

#### External functs.
read, malloc, free

* GNL 함수를 loop 안에서 호출하면 fd의 텍스트를 EOF가 올 때 까지 한 번에 한 줄씩 읽을 수 있다.
* GNL 함수를 처음 호출 했을 때 파일을 끝까지 읽었다 하더라도, 두 번째 호출했을 때는 두 번째 line부터 시작해야한다.
* file로부터, redirection으로부터, stdin으로부터 읽었을 때 함수가 제대로 동작해야 한다.
* 이 프로그램은 -D BUFFER_SIZE=xx 플래그를 붙여서 컴파일 해야 한다. \
즉, read 함수는 표준입력으로 또는 파일로부터 읽어들이기 위해서 컴파일할 때 정의된 BUFFER_SIZE를 사용해야 한다.
* BUFFER_SIZE가 1일 때도, 9999일 때도, 10000000 (1000만)일 때도 함수가 제대로 동작해야 한다.
* 다중 file descriptor를 관리 할 수 있는 함수로 만들기. 
