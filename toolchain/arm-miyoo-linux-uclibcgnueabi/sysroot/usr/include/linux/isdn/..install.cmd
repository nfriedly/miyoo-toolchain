cmd_/opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/linux/isdn/.install := /bin/bash scripts/headers_install.sh /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/linux/isdn ./include/uapi/linux/isdn capicmd.h; /bin/bash scripts/headers_install.sh /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/linux/isdn ./include/linux/isdn ; /bin/bash scripts/headers_install.sh /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/linux/isdn ./include/generated/uapi/linux/isdn ; for F in ; do echo "$(pound)include <asm-generic/$$F>" > /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/linux/isdn/$$F; done; touch /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/linux/isdn/.install
