cmd_/opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/asm/.install := /bin/bash scripts/headers_install.sh /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/asm ./arch/arm/include/uapi/asm auxvec.h byteorder.h fcntl.h hwcap.h ioctls.h kvm.h kvm_para.h mman.h perf_regs.h posix_types.h ptrace.h setup.h sigcontext.h signal.h stat.h statfs.h swab.h unistd.h; /bin/bash scripts/headers_install.sh /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/asm ./arch/arm/include/asm types.h; /bin/bash scripts/headers_install.sh /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/asm ./arch/arm/include/generated/uapi/asm ; for F in bitsperlong.h errno.h ioctl.h ipcbuf.h msgbuf.h param.h poll.h resource.h sembuf.h shmbuf.h siginfo.h socket.h sockios.h termbits.h termios.h; do echo "$(pound)include <asm-generic/$$F>" > /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/asm/$$F; done; touch /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/asm/.install