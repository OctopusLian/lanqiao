import java.util.Scanner;

public class Main{
    static int getBits(int k){
        int bits=0;
        while(k>0){
            int a=k%10;k/=10;
            if(a==0) return -1;
            int b=1<<a;
            if((bits&b)!=0) return -1;
            bits|=b;
        }return bits;
    }
    static int getBits2(int b){
        int lo=9;
        for(int i=1;i<1<<10;i<<=1)
            if((b&i)!=0) --lo;
        return lo;
    }
    public static void main(String[] args){
        // System.clearProperty("m.TEST");
        Scanner sc=System.getProperty("m.TEST")==null?new Scanner(System.in):
                new Scanner("999988");
        int sx=sc.nextInt();
        int[] ts={0,
                10,
                100,
                1000,
                10000,
                100000,
                1000000,
                10000000,
                100000000,
                1000000000,
        };
        int so=0;
        for(int a=1;a<sx;++a){
            int bits=getBits(a);
            if(bits==-1) continue;
            for(int b=1;;++b){
                int bts=getBits(b);
                if((bits&bts)!=0) continue;
                bts|=bits;
                long c=b*(sx-a);
                if(c>=ts[getBits2(bts)]) break;
                if((getBits((int)c)^bts)==1022)
                    ++so;
            }
        }System.out.println(so);
    }
}