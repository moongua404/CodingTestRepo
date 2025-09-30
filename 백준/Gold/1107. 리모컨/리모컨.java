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
        int target = getInt(br);
        int forbiddenCount = getInt(br);
        List<Integer> availableNumber = new ArrayList<>(List.of(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
        IntStream.range(0, forbiddenCount).forEach(ignored -> availableNumber.remove(Integer.valueOf(getInt(br))));

        char[] targetChars = String.valueOf(target).substring(1).toCharArray();
        char firstChar = String.valueOf(target).charAt(0);
        Optional<Integer> upperBefore = availableNumber.stream().filter(v -> v > (firstChar - 48)).min(Integer::compareTo);
        Optional<Integer> fitBefore = availableNumber.stream().filter(v -> v == (firstChar - 48)).findAny();
        Optional<Integer> lowerBefore = availableNumber.stream().filter(v -> v < (firstChar - 48)).max(Integer::compareTo);
        if (upperBefore.isEmpty()) {
            int rate = availableNumber.contains(0) ? 10 : 11;
            upperBefore = availableNumber.stream().filter(v -> v != 0).min(Integer::compareTo).map(v -> v * rate);
        }
        if (lowerBefore.isEmpty() && target >= 10) {
            lowerBefore = Optional.of(0);
        }

        for (char ch : targetChars) {
            Optional<Integer> max = availableNumber.stream().max(Integer::compareTo);
            Optional<Integer> min = availableNumber.stream().min(Integer::compareTo);
            Optional<Integer> fit = availableNumber.stream().filter(v -> v == (ch - 48)).findAny();
            Optional<Integer> upper = availableNumber.stream().filter(v -> v > (ch - 48)).min(Integer::compareTo);
            Optional<Integer> lower = availableNumber.stream().filter(v -> v < (ch - 48)).max(Integer::compareTo);

            Optional<Integer> upperC1 = Optional.empty();
            Optional<Integer> upperC2 = Optional.empty();
            Optional<Integer> fitC = Optional.empty();
            Optional<Integer> lowerC1 = Optional.empty();
            Optional<Integer> lowerC2 = Optional.empty();

            if (upperBefore.isPresent() && min.isPresent()) {
                upperC1 = Optional.of(Integer.parseInt(String.valueOf(upperBefore.get()) + min.get()));
            }
            if (fitBefore.isPresent() && upper.isPresent()) {
                upperC2 = Optional.of(Integer.parseInt(String.valueOf(fitBefore.get()) + upper.get()));
            }
            if (fitBefore.isPresent() && fit.isPresent()) {
                fitC = Optional.of(Integer.parseInt(String.valueOf(fitBefore.get()) + fit.get()));
            }
            if (lowerBefore.isPresent() && max.isPresent()) {
                lowerC1 = Optional.of(Integer.parseInt(String.valueOf(lowerBefore.get()) + max.get()));
            }
            if (fitBefore.isPresent() && lower.isPresent()) {
                lowerC2 = Optional.of(Integer.parseInt(String.valueOf(fitBefore.get()) + lower.get()));
            }

            if (upperC1.isEmpty()) {
                upperBefore = upperC2;
            } else if (upperC2.isEmpty()) {
                upperBefore = upperC1;
            } else {
                upperBefore = upperC1.get() < upperC2.get() ? upperC1 : upperC2;
            }

            if (lowerC1.isEmpty()) {
                lowerBefore = lowerC2;
            } else if (lowerC2.isEmpty()) {
                lowerBefore = lowerC1;
            } else {
                lowerBefore = lowerC1.get() > lowerC2.get() ? lowerC1 : lowerC2;
            }

            fitBefore = fitC;
        }

        int upperValue = upperBefore.orElse(1000000);
        int lowerValue = lowerBefore.orElse(1000000);
        int fitValue = fitBefore.orElse(1000000);

        int upperCost = Math.abs(upperValue - target) + String.valueOf(upperValue).length();
        int lowerCost = Math.abs(lowerValue - target) + String.valueOf(lowerValue).length();
        int fitCost = Math.abs(fitValue - target) + String.valueOf(fitValue).length();
        int defaultCost = Math.abs(100 - target);

        int min = Stream.of(upperCost, lowerCost, fitCost, defaultCost).min(Integer::compareTo).get();
        try {
            bw.write(min + "\n");
            bw.flush();
        } catch (Exception e) {}
    }
}
