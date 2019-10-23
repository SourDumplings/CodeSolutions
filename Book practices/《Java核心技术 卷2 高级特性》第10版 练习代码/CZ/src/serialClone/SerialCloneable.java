package serialClone;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

/**
 * A class whose clone method uses serialization.
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/23 17:28
 */
public class SerialCloneable implements Cloneable, Serializable
{
    public Object clone() throws CloneNotSupportedException
    {
        // save the object to a byte array
        try (ByteArrayOutputStream bout = new ByteArrayOutputStream())
        {
            try (ObjectOutputStream out = new ObjectOutputStream(bout))
            {
                out.writeObject(this);
            }

            // read a clone of the object from the byte array
            try (InputStream bin = new ByteArrayInputStream(bout.toByteArray()))
            {
                ObjectInputStream in = new ObjectInputStream(bin);
                return in.readObject();
            }
        }
        catch (IOException | ClassNotFoundException e)
        {
            CloneNotSupportedException e2 = new CloneNotSupportedException();
            e2.initCause(e);
            throw e2;
        }
    }
}
