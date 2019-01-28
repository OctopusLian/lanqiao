import java.io.*;
public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        String str[]=bf.readLine().split(" ");
        int v1=Integer.parseInt(str[0]);
        int v2=Integer.parseInt(str[1]);
        int t=Integer.parseInt(str[2]);
        int s=Integer.parseInt(str[3]);
        int l=Integer.parseInt(str[4]);
        int x=0,y=0,time=0;
        for(int i=1;i<=l;i++){
            if(x-y<t){
                x+=v1;
                y+=v2;               
            }
            else{
                for(int j=1;j<=s;j++){
                    i=i+1;
                   y+=v2;
                if(y==l)
                    break;
                }
                i=i-1;
            }
            if(x==l||y==l){
                time=i;
                break;
        }
        }
        if(y==l&&x<l)
            System.out.println("T");
        if(x==l&&y<l)
            System.out.println("R");
        if(y==l&&x==l)
            System.out.println("D");
        System.out.println(time);
    }
}
