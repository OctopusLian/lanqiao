import java.io.*;
import java.util.*;
public class Main{
    static Map<String,Integer> hm1=new HashMap<String,Integer>();
    static Map<String,Integer> hm2=new HashMap<String,Integer>();
    public static void main(String args[]) throws IOException{
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        String start=bf.readLine();
        String end=bf.readLine();
        char[][] a=new char[3][3];
        char[][] b=new char[3][3];
        int c=0,x1=0,y1=0,x2=0,y2=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j]=start.charAt(c);
                b[i][j]=end.charAt(c);
                c++;
                if(a[i][j]=='.'){
                    x1=i;
                    y1=j;
                }
                if(b[i][j]=='.'){
                    x2=i;
                    y2=j;
                }
            }
        }
        Node node1=new Node(0,x1,y1,a);
        Node node2=new Node(0,x2,y2,b);
         
        Queue<Node> qnode1=new LinkedList<Node>();
        Queue<Node> qnode2=new LinkedList<Node>();
        qnode1.add(node1);
        qnode2.add(node2);
        hm1.put(node1.gettu(), 0);
        hm2.put(node2.gettu(), 0);
         
        System.out.println(bfs(qnode1,qnode2));
    }
    public static int bfs(Queue<Node> q1,Queue<Node> q2){
        while(!q1.isEmpty()||!q2.isEmpty()){
             
            if(!q1.isEmpty()){
                Node node=q1.poll();
                 
                int x=node.getX();
                int y=node.getY();
                if(hm2.containsKey(node.gettu())){
                    return node.getSum()+hm2.get(node.gettu());
                }
                if(x>0){
                    char[][] c=node.getCopy();
                    c[x][y]=c[x-1][y];
                    c[x-1][y]='.';
                    Node node2=new Node(node.sum+1,x-1,y,c);
                    String s=node2.gettu();
                    if(hm2.containsKey(s)){
                        return node2.getSum()+hm2.get(node2.gettu());
                    }
                    if(!hm1.containsKey(s)){
                        hm1.put(s,node2.getSum());
                        q1.add(node2);
                    }
                }
                if(x<2){
                    char[][] c=node.getCopy();
                    c[x][y]=c[x+1][y];
                    c[x+1][y]='.';
                    Node node2=new Node(node.sum+1,x+1,y,c);
                    String s=node2.gettu();
                    if(hm2.containsKey(s)){
                        return node2.getSum()+hm2.get(s);
                    }
                    if(!hm1.containsKey(s)){
                        hm1.put(s,node2.getSum());
                        q1.add(node2);
                    }
                }
                if(y>0){
                    char[][] c=node.getCopy();
                    c[x][y]=c[x][y-1];
                    c[x][y-1]='.';
                    Node node2=new Node(node.sum+1,x,y-1,c);
                    String s=node2.gettu();
                    if(hm2.containsKey(s)){
                        return node2.getSum()+hm2.get(s);
                    }
                    if(!hm1.containsKey(s)){
                        hm1.put(s,node2.getSum());
                        q1.add(node2);
                    }
                }
                if(y<2){
                    char[][] c=node.getCopy();
                    c[x][y]=c[x][y+1];
                    c[x][y+1]='.';
                    Node node2=new Node(node.sum+1,x,y+1,c);
                    String s=node2.gettu();
                    if(hm2.containsKey(s)){
                        return node2.getSum()+hm2.get(s);
                    }
                    if(!hm1.containsKey(s)){
                        hm1.put(s,node2.getSum());
                        q1.add(node2);
                    }
                }
            }
            if(!q2.isEmpty()){
                Node node=q2.poll();
                int x=node.getX();
                int y=node.getY();
                if(hm1.containsKey(node.gettu())){
                    return node.getSum()+hm1.get(node.gettu());
                }
                if(x>0){
                    char[][] c=node.getCopy();
                    c[x][y]=c[x-1][y];
                    c[x-1][y]='.';
                    Node node2=new Node(node.sum+1,x-1,y,c);
                    String s=node2.gettu();
                    if(hm1.containsKey(s)){
                        return node2.getSum()+hm1.get(s);
                    }
                    if(!hm2.containsKey(s)){
                        hm2.put(s,node2.getSum());
                        q2.add(node2);
                    }
                }
                if(x<2){
                    char[][] c=node.getCopy();
             
                    c[x][y]=c[x+1][y];
                    c[x+1][y]='.';
                    Node node2=new Node(node.sum+1,x+1,y,c);
                    String s=node2.gettu();
                    if(hm1.containsKey(s)){
                        return node2.getSum()+hm1.get(s);
                    }
                    if(!hm2.containsKey(s)){
                        hm2.put(s,node2.getSum());
                        q2.add(node2);
                    }
                }
                if(y>0){
                    char[][] c=node.getCopy();
                    c[x][y]=c[x][y-1];
                    c[x][y-1]='.';
                    Node node2=new Node(node.sum+1,x,y-1,c);
                    String s=node2.gettu();
                    if(hm1.containsKey(s)){
                        return node2.getSum()+hm1.get(s);
                    }
                    if(!hm2.containsKey(s)){
                        hm2.put(s,node2.getSum());
                        q2.add(node2);
                    }
                }
                if(y<2){
                    char[][] c=node.getCopy();
                    c[x][y]=c[x][y+1];
                    c[x][y+1]='.';
                    Node node2=new Node(node.sum+1,x,y+1,c);
                    String s=node2.gettu();
                    if(hm1.containsKey(s)){
                        return node2.getSum()+hm1.get(s);
                    }
                    if(!hm2.containsKey(s)){
                        hm2.put(s,node2.getSum());
                        q2.add(node2);
                    }
                }
            }
             
        }
         
        return -1;
    }
}
class Node{
    int sum,x,y;
    char[][] c=null;
    public char[][] getCopy(){
        char[][] copy=new char[3][3];
         
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                copy[i][j]=c[i][j];
            }
        }
        return copy;
    }
    public String gettu(){
        StringBuffer s=new StringBuffer();
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                s.append(c[i][j]);
            }
        }
        return s.toString();
    }
    public Node(int sum, int x, int y, char[][] c) {
        super();
        this.sum = sum;
        this.x = x;
        this.y = y;
        this.c = c;
    }
    public int getSum() {
        return sum;
    }
    public void setSum(int sum) {
        this.sum = sum;
    }
    public int getX() {
        return x;
    }
    public void setX(int x) {
        this.x = x;
    }
    public int getY() {
        return y;
    }
    public void setY(int y) {
        this.y = y;
    }
}