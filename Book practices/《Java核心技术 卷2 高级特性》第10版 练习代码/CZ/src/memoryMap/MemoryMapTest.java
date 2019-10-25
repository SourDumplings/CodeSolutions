package memoryMap;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileChannel.MapMode;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.zip.CRC32;

/**
 * This program computes the CRC checksum of a file in four ways.<br>
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/25 18:00
 */
public class MemoryMapTest
{
    public static void main(String[] args) throws IOException
    {
        System.out.println("Please input filepath:");
        Scanner sc = new Scanner(System.in);
        String filepath = sc.nextLine();
        sc.close();

        // Input Stream
        System.out.println("Input Stream:");
        long start = System.currentTimeMillis();
        Path filename = Paths.get(filepath);
        long crcValue = checksumInputStream(filename);
        long end = System.currentTimeMillis();
        System.out.println(Long.toHexString(crcValue));
        System.out.println((end - start) + " milliseconds");

        // Buffered Input Stream
        System.out.println("Buffered Input Stream:");
        start = System.currentTimeMillis();
        filename = Paths.get(filepath);
        crcValue = checksumBufferedInputStream(filename);
        end = System.currentTimeMillis();
        System.out.println(Long.toHexString(crcValue));
        System.out.println((end - start) + " milliseconds");

        // Random Access File
        System.out.println("Random Access File:");
        start = System.currentTimeMillis();
        filename = Paths.get(filepath);
        crcValue = checksumRandomAccessFile(filename);
        end = System.currentTimeMillis();
        System.out.println(Long.toHexString(crcValue));
        System.out.println((end - start) + " milliseconds");

        // Mapped File
        System.out.println("Mapped File:");
        start = System.currentTimeMillis();
        filename = Paths.get(filepath);
        crcValue = checksumMappedFile(filename);
        end = System.currentTimeMillis();
        System.out.println(Long.toHexString(crcValue));
        System.out.println((end - start) + " milliseconds");
    }

    public static long checksumInputStream(Path filename) throws IOException
    {
        try (InputStream in = Files.newInputStream(filename))
        {
            CRC32 crc = new CRC32();

            int c;
            while ((c = in.read()) != -1)
            {
                crc.update(c);
            }
            return crc.getValue();
        }
    }

    public static long checksumBufferedInputStream(Path filename) throws IOException
    {
        try (InputStream in = new BufferedInputStream(Files.newInputStream(filename)))
        {
            CRC32 crc = new CRC32();

            int c;
            while ((c = in.read()) != -1)
            {
                crc.update(c);
            }
            return crc.getValue();
        }
    }

    public static long checksumRandomAccessFile(Path filename) throws IOException
    {
        try (RandomAccessFile file = new RandomAccessFile(filename.toFile(), "r"))
        {
            long length = file.length();
            CRC32 crc = new CRC32();

            for (long p = 0; p < length; p++)
            {
                file.seek(p);
                int c = file.readByte();
                crc.update(c);
            }
            return crc.getValue();
        }
    }

    public static long checksumMappedFile(Path filename) throws IOException
    {
        try (FileChannel fileChannel = FileChannel.open(filename))
        {
            CRC32 crc = new CRC32();
            int length = (int) fileChannel.size();
            MappedByteBuffer buffer = fileChannel.map(MapMode.READ_ONLY, 0, length);

            for (int p = 0; p < length; p++)
            {
                int c = buffer.get(p);
                crc.update(c);
            }
            return crc.getValue();
        }
    }
}
