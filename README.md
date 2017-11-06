This code is an example of a simple function overloading in pure C.
To compile:
gcc prog.c
./a.out

The output will be:
in max() for int
max (should be 3) = 3
in max() for float
max (should be 6.5) = 6.500000


== explanation ==
The major problem to overcome, is that we need to decide which function to call in some point of time.
We cannot know types in preprocessing time, only in compile time.
I have no intention to change the compiler, so compile time is also out.
Which means I can only determine the type during runtime. (Note that the check is simple enough to be optimized by the compiler to not be performed during runtime)

Dirty tricks I used:
1. A useful syntax for macros is that if I have an expression of this form: ({1, 2, 3, 4}), its value will be the last argument, e,g 4.
2. The array char[] x = {0xa, 0xa, 0xa, 0xa} equals to float(0), but not equals to int(0)
3. typeof(A) will be evaluated correctly during compile time to how the type of A

I tested it on my clean Ubuntu 16.04. If you having any trouble reproducing, the output of `gcc -v` is:


Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/5/lto-wrapper
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 5.4.0-6ubuntu1~16.04.5' --with-bugurl=file:///usr/share/doc/gcc-5/README.Bugs --enable-languages=c,ada,c++,java,go,d,fortran,objc,obj-c++ --prefix=/usr --program-suffix=-5 --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --with-system-zlib --disable-browser-plugin --enable-java-awt=gtk --enable-gtk-cairo --with-java-home=/usr/lib/jvm/java-1.5.0-gcj-5-amd64/jre --enable-java-home --with-jvm-root-dir=/usr/lib/jvm/java-1.5.0-gcj-5-amd64 --with-jvm-jar-dir=/usr/lib/jvm-exports/java-1.5.0-gcj-5-amd64 --with-arch-directory=amd64 --with-ecj-jar=/usr/share/java/eclipse-ecj.jar --enable-objc-gc --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.5) 
