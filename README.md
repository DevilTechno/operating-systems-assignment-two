# operating-systems-assignment-two

**Implement the Banker’s algorithm to answer the following question： Is the system in a safe state? If Yes, then what is the safe sequence?**

The answer to the following question is that the system is in a safe state, this safe sequence can be seen in the following screenshot:

![image](https://user-images.githubusercontent.com/31938399/235051506-feef53df-0560-4acc-9c50-95f3c3eb24c9.png)

This was gotten by reading in variables from the file **input.txt**

The data from this file shows as following:

![image](https://user-images.githubusercontent.com/31938399/235051592-69917f99-e5bc-47e8-8db2-3cf4ce767705.png)

The first two numbers are the maximum numbers of processes and resources for this problem, which can be changed to run other problems if need be, with the rest of the information being the numbers given from the example problem here:

![image](https://user-images.githubusercontent.com/31938399/235051693-b06c1309-ff9e-4455-b3bb-98a83bde9374.png)

The main issue I faced with this problem was that I could not figure out how to let go of resources at the end, often times either reporting the wrong safe sequence of that the system was unsafe. 

The way to run this program is to run

`gcc banker.c`

And then with the input.txt file in the same folder, run

`./a.out`
