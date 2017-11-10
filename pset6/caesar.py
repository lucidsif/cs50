# write a cipher algorithm that takes an argv of integer and string and shift each letter in the string by the integer
# import cs50 and sys
import cs50
import sys
# if argv is not 3, exit
if (len(sys.argv) != 3):
    print('please enter plaintext(string) and key(int)')
    sys.exit(1)
# second argv is plaintext/string
plaintext = sys.argv[1]
plaintext = plaintext.upper()
# third argv i key/integer
key = sys.argv[2]
key = int(key)
#for each letter in the string, print its ascii code + key
for index in range(len(plaintext)):
    letter = plaintext[index]
    # convert to alphabetical index
    alphabeticalIndex = ord(letter) - 65
    # convert to cipherLetter
    cipherIndex = (alphabeticalIndex + key) % 26
    # convert to ascii valuee
    asciiValue = chr(cipherIndex + 65)
    print(asciiValue, end='')
    
print('\n')