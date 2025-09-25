import java.io.*;
import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        mainLogic(br, bw);
        br.close();
        bw.close();
    }

    private static int getInt(BufferedReader br) {
        StringBuilder  sb = new StringBuilder();
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
        int testCaseCount = getInt(br);
        IntStream.range(0, testCaseCount).forEach(ignored -> testCase(br, bw));
    }

    private static void testCase(BufferedReader br, BufferedWriter bw) {
        int x = getInt(br);
        int y = getInt(br);
        int wormCount = getInt(br);
        CabbageMap cabbageMap = new CabbageMap(x, y);
        Queue<Pos> worms = new ArrayDeque<>();

        IntStream.range(0, wormCount).forEach(ignored -> {
            int curX = getInt(br);
            int curY = getInt(br);
            cabbageMap.setTrue(curX, curY);
            worms.add(new Pos(curX, curY));
        });

        int result = 0;

        while(!worms.isEmpty()) {
            Pos pos = worms.remove();
            if (cabbageMap.isTrue(pos.x, pos.y)) {
                result++;
                cabbageMap.spread(pos.x, pos.y);
            }
        }

        try {
            bw.write(result + "\n");
            bw.flush();
        } catch (Exception e) {}
    }
}

class CabbageMap {
    int maxX;
    int maxY;
    boolean[][] cabbageMap;

    CabbageMap(int x, int y) {
        this.maxX = x;
        this.maxY = y;
        cabbageMap = new boolean[x][y];
        for (int iy = 0; iy < y; iy++) {
            for (int ix = 0; ix < x; ix++) {
                cabbageMap[ix][iy] = false;
            }
        }
    }

    void setTrue(int x, int y) {
        cabbageMap[x][y] = true;
    }

    boolean isTrue(int x, int y) {
        return cabbageMap[x][y];
    }

    void spread(int x, int y) {
        Queue<Pos> poses = new ArrayDeque<>();
        cabbageMap[x][y] = false;
        poses.add(new Pos(x, y));

        while(!poses.isEmpty()) {
            Pos pos = poses.remove();

            Stream.of(new Pos(-1, 0), new Pos(1, 0), new Pos(0, -1), new Pos(0, 1))
                    .filter(direction -> direction.x + pos.x >= 0 && direction.x + pos.x < maxX
                            && direction.y + pos.y >= 0 && direction.y + pos.y < maxY
                            && cabbageMap[direction.x + pos.x][direction.y + pos.y])
                    .forEach(direction -> {
                        cabbageMap[direction.x + pos.x][direction.y + pos.y] = false;
                        poses.add(new Pos(direction.x + pos.x, direction.y + pos.y));
                    });
        }
    }
}

class Pos {
    int x;
    int y;
    Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }
}