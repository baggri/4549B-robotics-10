import time
print("lets fucking go FIZZBUZZ LITTTTYYYY made by swag")
time.sleep(1)
for i in range(1,100):
    if i % 5 == 0 and i % 3 == 0:
        print("FizzBitchuzz")
    elif i % 5 == 0:
        print('Buzz')
    elif i % 3 == 0:
        print("Fizz")
    else:
        print(i)
    time.sleep(0.3)
