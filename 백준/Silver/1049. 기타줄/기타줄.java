import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        mainLogic(br, bw);
        br.close();
        bw.close();
    }

    private static int getInt(BufferedReader br) {
        StringBuilder sb = new StringBuilder();
        try {
            int val = br.read();
            while(val != 32 && val != 10) {
                sb.append((char) val);
                val = br.read();
            }
        } catch (IOException ignored) {}

        return Integer.parseInt(sb.toString());
    }

    private static void mainLogic(BufferedReader br, BufferedWriter bw) {
        int N = getInt(br);
        int M = getInt(br);
        int packageMin = Integer.MAX_VALUE;
        int eachMin = Integer.MAX_VALUE;

        for (int i = 0; i < M; i++) {
            int temp1 = getInt(br);
            int temp2 = getInt(br);
            packageMin = Math.min(packageMin, temp1);
            eachMin = Math.min(eachMin, temp2);
        }

        int price = 0;
        if (eachMin * 6 < packageMin) {
            price = N * eachMin;
        } else {
            price += packageMin * (N / 6);
            N %= 6;
            price += (eachMin * N < packageMin) ? eachMin * N : packageMin;
        }

        try {
            bw.write(price + "\n");
            bw.flush();
        } catch (Exception e) {}
    }
}
