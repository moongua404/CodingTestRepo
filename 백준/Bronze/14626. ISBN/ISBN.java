import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        mainLogic(br, bw);
        br.close();
        bw.close();
    }

    private static void mainLogic(BufferedReader br, BufferedWriter bw) throws IOException {
        int oddWeight = 3;
        int evenWeight = 1;

        String line = br.readLine();
        int index = line.indexOf('*');
        line = line.replace('*', '0');

        int sum = 0;
        char[] chars = line.toCharArray();
        for (int i = 0; i < 12; i++) {
            sum += (chars[i] - 48) * ((i % 2 == 0) ? evenWeight : oddWeight);
        }
        sum += (chars[12] - 48);
        int foundX = (10 - (sum % 10)) % 10;

        int x = (index % 2 != 0) ? Xtox(foundX) : foundX % 10;

        bw.write(x + "\n");
        bw.flush();
    }

    private static int Xtox(int v) {
        if (v % 3 == 0) {
            return (v/3);
        } else if ((v+10) % 3 == 0) {
            return ((v+10)/3);
        }
        return (v+20) / 3;
    }
}
