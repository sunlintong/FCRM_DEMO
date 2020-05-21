import logging
import os 


file = open("slt", mode="r")
# ll = file.readlines()
# ll.insert(0, "aaa\n")
# ll.insert(1, "bbb\n")

# file = open("slt", mode="w")
# file.write("".join(ll))

print(file.read())
# file.seek(0)
print(file.readlines())