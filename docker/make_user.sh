#!/bin/bash
#
#[使い方]
#
#実行権限を与える
# chmod 755 ./useradd.sh
#
#第一引数にユーザー名、第二引数にパスワードを書いて実行
# ./useradd.sh username passwd
#


if [ $# -ne 2 ]; then
 echo "error"
 exit 1
fi

CHECKFLG=`cat /etc/passwd | grep "^$1:" | wc -l`

if [ $CHECKFLG -ne 0 ]; then
 echo "duplicate error"
 exit 1
fi

# make user
/usr/sbin/useradd $1 -m

# set user passwd
echo $1":"$2 | /usr/sbin/chpasswd

# chgroup
#作ったユーザーのグループを指定したいときはコメントアウトをはずす
#usermod -g users $1
