def main():
    print('Please enter howv many lines of data to add to a')
    print('file, then specify the contents of that new data. \n')
    try:
        text = open('file_changes.txt','a')
        num = int(input('How many lines? (Enter 1 or 2:) '))
        if num == 1:
            print('You chose to add 1 line of data.\n')
        else:
            print('You chose to add 2 lines of data.\n')
        
        print('What would you like to add to the file?')
        for i in range(num):
            line = input('line' +str(i+1)+':')
            text.write(line+'\n')
        text.close()
        print("\nNOTE:file_changes.txt has been updated.")
    except Error:
        print(Error)
main()