import java.io.*;
        public class Main {
            public static void main(String[] args)throws IOException {
            BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
            String str=buf.readLine();
            String s[]=str.split(" ");
            StringBuffer bf=new StringBuffer();
             int i=Integer.parseInt(s[0]);
            int n=Integer.parseInt(s[1]);
            switch(i){
            case 0:{
                bf.append("zero ");
                break;
            }
            case 1:{
                bf.append("one ");
                break;
            }
            case 2:{
                bf.append("two ");
                break;
            }
            case 3:{
                bf.append("three ");
                break;
            }
            case 4:{
                bf.append("four ");
                break;
            }
            case 5:{
                bf.append("five ");
                break;
            }
            case 6:{
                bf.append("six ");
                break;
            }
            case 7:{
                bf.append("seven ");
                break;
            }
            case 8:{
                bf.append("eight ");
                break;
            }
            case 9:{
                bf.append("nine ");
                break;
            }
            case 10:{
                bf.append("ten ");
                break;
            }
            case 11:{
                bf.append("eleven ");
                break;
            }
            case 12:{
                bf.append("twelve ");
                break;
            }
            case 13:{
                bf.append("thirteen ");
                break;
            }
            case 14:{
                bf.append("fourteen ");
                break;
            }
            case 15:{
                bf.append("fifteen ");
                break;
            }
            case 16:{
                bf.append("sixteen ");
                break;
            }
            case 17:{
                bf.append("seventeen ");
                break;
            }
            case 18:{
                bf.append("eighteen ");
                break;
            }
            case 19:{
                bf.append("nineteen ");
                break;
            }
            case 20:{
                bf.append("twenty ");
                break;
            }
            case 21:{
                bf.append("twenty one ");
                break;
            }
            case 22:{
                bf.append("twenty two ");
                break;
            }
            case 23:{
                bf.append("twenty three ");
                break;
            }
            
            }
            if(n==0){
                bf.append("o'clock");
            }
            else if(n/10<2){
                switch(n){
                case 1:{
                    bf.append("one");
                    break;
                }
                case 2:{
                    bf.append("two");
                    break;
                }
                case 3:{
                    bf.append("three");
                    break;
                }
                case 4:{
                    bf.append("Zero");
                    break;
                }
                case 5:{
                    bf.append("five");
                    break;
                }
                case 6:{
                    bf.append("six");
                    break;
                }
                case 7:{
                    bf.append("seven");
                    break;
                }
                case 8:{
                    bf.append("eight");
                    break;
                }
                case 9:{
                    bf.append("nine");
                    break;
                }
                case 10:{
                    bf.append("ten");
                    break;
                }
                case 11:{
                    bf.append("eleven");
                    break;
                }
                case 12:{
                    bf.append("twelve ");
                    break;
                }
                case 13:{
                    bf.append("thirteen ");
                    break;
                }
                case 14:{
                    bf.append("fourteen ");
                    break;
                }
                case 15:{
                    bf.append("fifteen ");
                    break;
                }
                case 16:{
                    bf.append("sixteen ");
                    break;
                }
                case 17:{
                    bf.append("seventeen ");
                    break;
                }
                case 18:{
                    bf.append("eighteen ");
                    break;
                }
                case 19:{
                    bf.append("nineteen ");
                    break;
                }
            }
         }
            else {
                switch(n/10){
                case 2:{
                    bf.append("twenty ");
                    break;
                }
                case 3:{
                    bf.append("thirty ");
                    break;
                }
                case 4:{
                    bf.append("forty ");
                    break;
                }
                case 5:{
                    bf.append("fifty ");
                    break;
                }
                
                
            }
                switch(n%10){
                case 1:{
                    bf.append("one");
                    break;
                }
                case 2:{
                    bf.append("two");
                    break;
                }
                case 3:{
                    bf.append("three");
                    break;
                }
                case 4:{
                    bf.append("four");
                    break;
                }
                case 5:{
                    bf.append("five");
                    break;
                }
                case 6:{
                    bf.append("six");
                    break;
                }
                case 7:{
                    bf.append("seven");
                    break;
                }
                case 8:{
                    bf.append("eight");
                    break;
                }
                case 9:{
                    bf.append("nine");
                    break;
                }
            }
}
            System.out.println(bf.toString());
            }
}