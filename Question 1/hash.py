import hashlib
def hash(x):              
    haha=hashlib.new("SHA256")
    haha.update(x.encode())
    return haha.hexdigest()
Alice_msg =input("Enter Alice's message:")
Alice_msg_hash=hash(Alice_msg)

def send_message(x):
    return x;

Bob_msg=send_message(Alice_msg)
Bob_msg_hash=send_message(Alice_msg_hash)
Bob_hash=hash(Bob_msg)

print('Received msg :',Bob_msg)
print('Received hash :',Bob_msg_hash)
print('Hashed msg by bob :',Bob_hash)
if (Bob_msg_hash==Bob_hash):
    print('Transmission Not tampered')
else:
    print('Transmission tampered')
