#!/bin/python3
import sys
import os
def illion(F):
    s=""
    I=len(str(F))
    I=int((I-1)/3)*3
    while 1:
        if I < 0:
            break
        f=int(int(F)/pow(10,I))%1000
        match f:
            case 1:
                s+='m'
            case 2:
                s+='b'
            case 3:
                s+="tr"
            case 4:
                s+="quadr"
            case 5:
                s+="quint"
            case 6:
                s+="sext"
            case 7:
                s+="sept"
            case 8:
                s+="oct"
            case 9:
                s+="non"
            case 0:
                s+="n"
            case _:
                f1=f%10
                f2=int(f/10)%10
                f3=int(f/100)%10
                match(f1):
                    case 1:
                        s+="un"
                    case 2:
                        s+="duo"
                    case 3:
                        s+="tre"
                    case 4:
                        s+="quattuor"
                    case 5:
                        if f2>0 and f2<4:
                            s+="quin"
                        else:
                            s+="quinqua"
                    case 6:
                        s+="se"
                    case 7:
                        s+="septe"
                    case 8:
                        s+="octo"
                    case 9:
                        s+="nove"
                if f1==3 or f1==6:
                    if f2>0:
                        if 2<=f2<=5:
                            s+="s"
                        elif f2==8:
                            s+="x"
                    elif 3<=f3<=5:
                        s+="s"
                    elif f3==1 or f3==8:
                        s+="x"
                elif f1==7 or f1==9:
                    if f2>0:
                        if f2==1 or 3<=f2<=7:
                            s+="n"
                        elif f2==2 or f2==8:
                            s+="m"
                    else:
                        if 1<=f3<=7:
                            s+="n"
                        elif f3==8:
                            s+="m"
                match f2:
                    case 1:
                        s+="deci"
                    case 2:
                        s+="viginti"
                    case 3:
                        s+="triginta"
                    case 4:
                        s+="quadraginta"
                    case 5:
                        s+="quinquaginta"
                    case 6:
                        s+="sexaginta"
                    case 7:
                        s+="septuaginta"
                    case 8:
                        s+="octoginta"
                    case 9:
                        s+="nonaginta"
                match f3:
                    case 1:
                        s+="centi"
                    case 2:
                        s+="ducenti"
                    case 3:
                        s+="trecenti"
                    case 4:
                        s+="quadringenti"
                    case 5:
                        s+="quingenti"
                    case 6:
                        s+="sescenti"
                    case 7:
                        s+="septingenti"
                    case 8:
                        s+="octingenti"
                    case 9:
                        s+="nongenti"
        if s[-1]=="a" or s[-1]=="i":
            s=s[:-1]
        s+="illi"
        I-=3
    return s+"on"
def NumbersToWords(n):
    if n[0]=='-':
        print("minus ",end='')
        n=n[1:]
    if n=="" or n=="0":
        print("zero")
        return
    s=""
    l=len(n)
    i=0
    e=3-((l-1)%3)
    ff=int((l-1)/3)
    while 1:
        if i>=l:
            break
        t=0
        while 1:
            if e>=4:
                break
            o=n[i]
            if o=='0':
                e+=1
                i+=1
                continue
            else:
                t=1
            if e==2:
                match o:
                    case '1':
                        e+=1
                        i+=1
                        match(n[i]):
                            case '0':
                                s+="ten"
                            case '1':
                                s+="eleven"
                            case '2':
                                s+="twelve"
                            case '3':
                                s+="thirteen"
                            case '4':
                                s+="fourteen"
                            case '5':
                                s+="fifteen"
                            case '6':
                                s+="sixteen"
                            case '7':
                                s+="seventeen"
                            case '8':
                                s+="eighteen"
                            case '9':
                                s+="nineteen"
                    case '2':
                        s+="twenty"
                    case '3':
                        s+="thirty"
                    case '4':
                        s+="fourty"
                    case '5':
                        s+="fifty"
                    case '6':
                        s+="sixty"
                    case '7':
                        s+="seventy"
                    case '8':
                        s+="eighty"
                    case '9':
                        s+="ninety"
            else:
                match o:
                    case '1':
                        s+="one"
                    case '2':
                        s+="two"
                    case '3':
                        s+="three"
                    case '4':
                        s+="four"
                    case '5':
                        s+="five"
                    case '6':
                        s+="six"
                    case '7':
                        s+="seven"
                    case '8':
                        s+="eight"
                    case '9':
                        s+="nine"
                if e==1 and o!='0':
                    s+=" hundred"
            s+=' '
            e+=1
            i+=1
        if t:
            match ff:
                case 0:
                    e=1
                    ff-=1
                    continue
                case 1:
                    s+="thousand"
                case _:
                    s+=illion(ff-1)
            s+=' '
        e=1
        ff-=1
    print(s[:-1])
argc=len(sys.argv)
I=0
argi=1
if argc>1:
    if sys.argv[1]=="-i":
        I=1
        argi+=1
if I:
    if argc>argi:
        for i in range(argi,argc):
            print(illion(int(sys.argv[i])))
    else:
        for testt in sys.stdin:
            print(illion(testt.strip()))
else:
    if argc>argi:
        for i in range(argi,argc):
            NumbersToWords(sys.argv[i])
    else:
        for testt in sys.stdin:
            NumbersToWords(testt.strip())
