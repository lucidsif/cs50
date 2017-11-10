# import get_int from cs50 library
import cs50
n = cs50.get_int()
# space_counter (sc) = n - 1
sc = n - 1
# hash_counter (hc) = 2;
hc = 2
# for each line until n;
for x in range(n):
    # initialize line = "";
    stringLine = ""
    # append (sc) spaces to string
    stringLine += (sc) * " "
    # append (hc) hashes to string
    stringLine += (hc) * "#"
    # print line 
    print(stringLine)
    # --sc
    sc -= 1
    # ++hc
    hc += 1
    
    
    
    
