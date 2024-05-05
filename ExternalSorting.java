import java.io.*;
import java.util.*;

public class ExternalSorting {

    // Function to perform external sorting
    public static void externalSort(String inputFile, String outputFile, int memorySize) throws IOException {
        List<Integer> buffer = new ArrayList<>(memorySize);

        try (BufferedReader br = new BufferedReader(new FileReader(inputFile))) {
            String line;
            while ((line = br.readLine()) != null) {
                buffer.add(Integer.parseInt(line));
                if (buffer.size() == memorySize) {
                    Collections.sort(buffer);
                    try (BufferedWriter bw = new BufferedWriter(new FileWriter(new File("temp.txt")))) {
                        for (int num : buffer) {
                            bw.write(Integer.toString(num));
                            bw.newLine();
                        }
                    }
                    buffer.clear();
                }
            }

            if (!buffer.isEmpty()) {
                Collections.sort(buffer);
                try (BufferedWriter bw = new BufferedWriter(new FileWriter(new File("temp.txt")))) {
                    for (int num : buffer) {
                        bw.write(Integer.toString(num));
                        bw.newLine();
                    }
                }
            }
        }

        mergeChunks("temp.txt", outputFile);
    }

    // Function to merge sorted chunks
    private static void mergeChunks(String inputFile, String outputFile) throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(inputFile));
             BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile))) {
            String line;
            PriorityQueue<Integer> minHeap = new PriorityQueue<>();

            while ((line = br.readLine()) != null) {
                minHeap.add(Integer.parseInt(line));
                if (minHeap.size() == 100) {
                    while (!minHeap.isEmpty()) {
                        bw.write(Integer.toString(minHeap.poll()));
                        bw.newLine();
                    }
                }
            }

            while (!minHeap.isEmpty()) {
                bw.write(Integer.toString(minHeap.poll()));
                bw.newLine();
            }
        }
    }

    public static void main(String[] args) {
        String inputFile = "input.txt";
        String outputFile = "output.txt";
        int memorySize = 100;

        try {
            externalSort(inputFile, outputFile, memorySize);
            System.out.println("External sorting completed successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
