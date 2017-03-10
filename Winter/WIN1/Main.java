import java.util.*;
import java.math.*;

public class Main{
    public static void main(String args[])
    {
        BigInteger a,b,c;  
        Scanner cin = new Scanner(System.in);
        a = cin.nextBigInteger();
        b = cin.nextBigInteger();
        c = cin.nextBigInteger();
        BigInteger num[] = new BigInteger [3];
        num[0] = a;
        num[1] = b;
        num[2] = c; 
        int flag = 0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    BigInteger tmp = num[i].add(num[j]);
                    if(tmp.equals(num[k]))
                    flag=1;
                }
            }
        }
        if(flag==1)
        System.out.println("YES");
        else
        System.out.println("NO");

    }
}