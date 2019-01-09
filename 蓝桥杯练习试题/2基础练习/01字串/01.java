public class Main{
    public static void main (String args[]){
        
    for(int a1=0;a1<2;a1++){
        for(int a2=0;a2<2;a2++){
            for(int a3=0;a3<2;a3++){
                for(int a4=0;a4<2;a4++){
                    for(int a5=0;a5<2;a5++){
                        StringBuffer s=new StringBuffer();
                        System.out.println(s.append(a1).append(a2).append(a3).append(a4).append(a5));
                    }
                }
            }
        }
    }
    
    }
}