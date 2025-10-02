import java.io.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

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
        long D = getInt(br);
        Map<CName, College> colleges = new HashMap<>();
        colleges.put(CName.Info, new College(CName.Info, new Effect(List.of(CName.Electro, CName.Future))));
        colleges.put(CName.Electro, new College(CName.Electro, new Effect(List.of(CName.Belief, CName.Future, CName.Info))));
        colleges.put(CName.Future, new College(CName.Future, new Effect(List.of(CName.HGJ, CName.Belief, CName.Electro, CName.Info))));
        colleges.put(CName.Belief, new College(CName.Belief, new Effect(List.of(CName.Electro, CName.Future, CName.HGJ, CName.Truth))));
        colleges.put(CName.HGJ, new College(CName.HGJ, new Effect(List.of(CName.Future, CName.Belief, CName.Truth, CName.Engineering))));
        colleges.put(CName.Truth, new College(CName.Truth, new Effect(List.of(CName.Belief, CName.HGJ, CName.Students))));
        colleges.put(CName.Students, new College(CName.Students, new Effect(List.of(CName.Truth, CName.Engineering))));
        colleges.put(CName.Engineering, new College(CName.Engineering, new Effect(List.of(CName.Students, CName.HGJ))));

        long rate = 1;
        while(rate / 2 < D) {
            for (Entry<CName, College> entry : colleges.entrySet()) {
                Effect currentEffect = entry.getValue().effectMap.get(rate);
                Effect newEffect = new Effect(new HashMap<>());

                long finalRate = rate;
                currentEffect.effectMap.forEach((currentKey, currentValue) -> {
                    colleges.get(currentKey).effectMap.get(finalRate).effectMap.forEach((pastKey, pastValue) -> {
                        if (newEffect.effectMap.containsKey(pastKey)) {
                            newEffect.effectMap.put(pastKey, (newEffect.effectMap.get(pastKey) + currentValue * pastValue) % 1_000_000_007);
                        } else {
                            newEffect.effectMap.put(pastKey, (currentValue * pastValue) % 1_000_000_007);
                        }
                    });
                });
                entry.getValue().effectMap.put(rate * 2, newEffect);
            }
            rate *= 2;
        }

        long amount = 0;
        while(amount != D) {
            rate /= 2;
            if (amount + rate <= D) {
                for (Entry<CName, College> entry : colleges.entrySet()) {
                    Effect currentEffect = entry.getValue().effectMap.get(amount);
                    Effect newEffect = new Effect(new HashMap<>());

                    long finalRate = rate;
                    currentEffect.effectMap.forEach((currentKey, currentValue) -> {
                        colleges.get(currentKey).effectMap.get(finalRate).effectMap.forEach((pastKey, pastValue) -> {
                            if (newEffect.effectMap.containsKey(pastKey)) {
                                newEffect.effectMap.put(pastKey, (newEffect.effectMap.get(pastKey) + currentValue * pastValue) % 1_000_000_007);
                            } else {
                                newEffect.effectMap.put(pastKey, (currentValue * pastValue) % 1_000_000_007);
                            }
                        });
                    });
                    entry.getValue().effectMap.put(amount + rate, newEffect);
                }
                amount += rate;
            }
        }

        try {
            Long max = colleges.get(CName.Info).effectMap.get(D).effectMap.get(CName.Info);
            max = (max != null) ? max % 1_000_000_007 : 0;
            bw.write(max + "\n");
            bw.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

enum CName {
    Info, Electro, Future, Belief, HGJ, Truth, Students, Engineering
}

class College {
    CName collegeName;
    Map<Long, Effect> effectMap;

    College(CName collegeName, Effect effect) {
        this.collegeName = collegeName;
        effectMap = new HashMap<>();
        effectMap.put(1L, effect);
        effectMap.put(0L, new Effect(new HashMap<>()));
        effectMap.get(0L).effectMap.put(collegeName, 1L);
    }
}

class Effect {
    Map<CName, Long> effectMap;
    Effect(Map<CName, Long> effectMap) {
        this.effectMap = effectMap;
    }

    Effect(List<CName> presets) {
        effectMap = new HashMap<>();
        presets.forEach(name -> effectMap.put(name, 1L));
    }
}
