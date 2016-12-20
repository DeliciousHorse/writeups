from Crypto.PublicKey import RSA

privkey = open('privatekey.pem').read()
decryption_key = RSA.importKey(privkey)

iterations = 1480510736 % 14	# timestamp from filename

for i in range(1, 6):
	data = open('file_%d.locky' % (i,), 'rb').read()
	for _ in range(iterations):
		data = decryption_key.decrypt(data)
	open('file_%d.bin' % (i,), 'wb').write(data)
	
	