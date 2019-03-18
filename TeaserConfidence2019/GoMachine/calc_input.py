import string
import itertools
import sys
import struct

mod = [0x88ca6b51, 0x8405b751, 0xbfa08c87, 0x82013f23, 0x4666751b, 0x5271083f]
expected = [0xf2227a5, 0x4e053304, 0x706fc204, 0x4283b66c, 0x1e5cc83a, 0x1faf011c]

def calc_hash(input, mod):
    val = input
    for i in range(8):
        val = val*val % mod
    return val*input % mod

for i in range(len(mod)):
    for perm in itertools.permutations(string.printable, 4):
        input = struct.unpack('>I', ''.join(perm))[0]
        hash = calc_hash(input, mod[i])
        if hash == expected[i]:
            print ''.join(perm)
            break
