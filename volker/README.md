# This is to check few things with python and root...

## what to do

Make sure $ROOTSYS is set and do...

```
$ ./build.sh
$ cd test
$ ./run_test.sh
```

## options to build.sh

 - use cleanup to do what it says... (remove the compiled files and root files created by the tests...)
 - use realclean to [re]compile with ./lib ./bin ./include removed (sometimes needed)
 - use debug to enable the flag....

```
$ ./build.sh cleanup
$ ./build.sh realclean
$ ./build.sh debug
```

