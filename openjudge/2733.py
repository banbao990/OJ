##########################
# author:     banbao     #
# language:   python     #
# encoding:   utf-8      #
##########################

# link:http://bailian.openjudge.cn/practice/2733/

def main():
    year = int(input())
    if (year % 400 == 0) or (year % 4 == 0 and not (year % 100 == 0)):
        print('Y')
    else:
        print('N')

if __name__ == '__main__':
    main()

