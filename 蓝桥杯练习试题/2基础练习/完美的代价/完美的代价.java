import java.io.*;

public class Main{
    public static void main(String args[]) throws IOException {
        BufferedReader buf = new BufferedReader(
                new InputStreamReader(System.in));
        int n = Integer.parseInt(buf.readLine());
        String s = buf.readLine();
        char c[] = s.toCharArray();
        int count = 0, num = 0;
        char ch = '0';
        int i, k = 0, j;
        int b[] = new int[26];
        for (i = 0; i < n; i++)
            for (i = 0; i < n; i++) {
                j = c[i] - 'a';
                b[j]++;
            }
        for (j = 0; j < 26; j++) {
            if (b[j] % 2 != 0) {
                k++;
                ch = (char) (j + 'a');
            }
        }
        if (k >= 2)
            System.out.println("Impossible");
        else
            System.out.println(changes(c, ch, n));
    }

    public static int changes(char s[], char x, int n) {
        int i, change = 0, j, k;
        for (i = 0; i < n / 2; i++) {
            if (s[i] == x) {
                for (j = i; j < n - i - 1; j++)
                    if (s[n - i - 1] == s[j])
                        break;
                change += j - i;
                for (k = j; k > i; k--)
                    s[k] = s[k - 1];
                s[i] = s[n - i - 1];
            } else {
                for (j = n - i - 1; j >= i; j--)
                    if (s[i] == s[j])
                        break;
                change += n - i - 1 - j;
                for (k = j; k < n - i - 1; k++)
                    s[k] = s[k + 1];
                s[n - i - 1] = s[i];
            }
        }
        return change;
    }
}