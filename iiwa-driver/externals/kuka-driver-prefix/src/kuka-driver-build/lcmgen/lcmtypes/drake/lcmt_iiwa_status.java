/* LCM type definition class file
 * This file was automatically generated by lcm-gen
 * DO NOT MODIFY BY HAND!!!!
 */

package drake;
 
import java.io.*;
import java.util.*;
import lcm.lcm.*;
 
public final class lcmt_iiwa_status implements lcm.lcm.LCMEncodable
{
    public long timestamp;
    public int num_joints;
    public double joint_position_measured[];
    public double joint_position_commanded[];
    public double joint_position_ipo[];
    public double joint_velocity_estimated[];
    public double joint_torque_measured[];
    public double joint_torque_commanded[];
    public double joint_torque_external[];
 
    public lcmt_iiwa_status()
    {
    }
 
    public static final long LCM_FINGERPRINT;
    public static final long LCM_FINGERPRINT_BASE = 0xf1bdfa582d226b47L;
 
    static {
        LCM_FINGERPRINT = _hashRecursive(new ArrayList<Class<?>>());
    }
 
    public static long _hashRecursive(ArrayList<Class<?>> classes)
    {
        if (classes.contains(drake.lcmt_iiwa_status.class))
            return 0L;
 
        classes.add(drake.lcmt_iiwa_status.class);
        long hash = LCM_FINGERPRINT_BASE
            ;
        classes.remove(classes.size() - 1);
        return (hash<<1) + ((hash>>63)&1);
    }
 
    public void encode(DataOutput outs) throws IOException
    {
        outs.writeLong(LCM_FINGERPRINT);
        _encodeRecursive(outs);
    }
 
    public void _encodeRecursive(DataOutput outs) throws IOException
    {
        outs.writeLong(this.timestamp); 
 
        outs.writeInt(this.num_joints); 
 
        for (int a = 0; a < this.num_joints; a++) {
            outs.writeDouble(this.joint_position_measured[a]); 
        }
 
        for (int a = 0; a < this.num_joints; a++) {
            outs.writeDouble(this.joint_position_commanded[a]); 
        }
 
        for (int a = 0; a < this.num_joints; a++) {
            outs.writeDouble(this.joint_position_ipo[a]); 
        }
 
        for (int a = 0; a < this.num_joints; a++) {
            outs.writeDouble(this.joint_velocity_estimated[a]); 
        }
 
        for (int a = 0; a < this.num_joints; a++) {
            outs.writeDouble(this.joint_torque_measured[a]); 
        }
 
        for (int a = 0; a < this.num_joints; a++) {
            outs.writeDouble(this.joint_torque_commanded[a]); 
        }
 
        for (int a = 0; a < this.num_joints; a++) {
            outs.writeDouble(this.joint_torque_external[a]); 
        }
 
    }
 
    public lcmt_iiwa_status(byte[] data) throws IOException
    {
        this(new LCMDataInputStream(data));
    }
 
    public lcmt_iiwa_status(DataInput ins) throws IOException
    {
        if (ins.readLong() != LCM_FINGERPRINT)
            throw new IOException("LCM Decode error: bad fingerprint");
 
        _decodeRecursive(ins);
    }
 
    public static drake.lcmt_iiwa_status _decodeRecursiveFactory(DataInput ins) throws IOException
    {
        drake.lcmt_iiwa_status o = new drake.lcmt_iiwa_status();
        o._decodeRecursive(ins);
        return o;
    }
 
    public void _decodeRecursive(DataInput ins) throws IOException
    {
        this.timestamp = ins.readLong();
 
        this.num_joints = ins.readInt();
 
        this.joint_position_measured = new double[(int) num_joints];
        for (int a = 0; a < this.num_joints; a++) {
            this.joint_position_measured[a] = ins.readDouble();
        }
 
        this.joint_position_commanded = new double[(int) num_joints];
        for (int a = 0; a < this.num_joints; a++) {
            this.joint_position_commanded[a] = ins.readDouble();
        }
 
        this.joint_position_ipo = new double[(int) num_joints];
        for (int a = 0; a < this.num_joints; a++) {
            this.joint_position_ipo[a] = ins.readDouble();
        }
 
        this.joint_velocity_estimated = new double[(int) num_joints];
        for (int a = 0; a < this.num_joints; a++) {
            this.joint_velocity_estimated[a] = ins.readDouble();
        }
 
        this.joint_torque_measured = new double[(int) num_joints];
        for (int a = 0; a < this.num_joints; a++) {
            this.joint_torque_measured[a] = ins.readDouble();
        }
 
        this.joint_torque_commanded = new double[(int) num_joints];
        for (int a = 0; a < this.num_joints; a++) {
            this.joint_torque_commanded[a] = ins.readDouble();
        }
 
        this.joint_torque_external = new double[(int) num_joints];
        for (int a = 0; a < this.num_joints; a++) {
            this.joint_torque_external[a] = ins.readDouble();
        }
 
    }
 
    public drake.lcmt_iiwa_status copy()
    {
        drake.lcmt_iiwa_status outobj = new drake.lcmt_iiwa_status();
        outobj.timestamp = this.timestamp;
 
        outobj.num_joints = this.num_joints;
 
        outobj.joint_position_measured = new double[(int) num_joints];
        if (this.num_joints > 0)
            System.arraycopy(this.joint_position_measured, 0, outobj.joint_position_measured, 0, this.num_joints); 
        outobj.joint_position_commanded = new double[(int) num_joints];
        if (this.num_joints > 0)
            System.arraycopy(this.joint_position_commanded, 0, outobj.joint_position_commanded, 0, this.num_joints); 
        outobj.joint_position_ipo = new double[(int) num_joints];
        if (this.num_joints > 0)
            System.arraycopy(this.joint_position_ipo, 0, outobj.joint_position_ipo, 0, this.num_joints); 
        outobj.joint_velocity_estimated = new double[(int) num_joints];
        if (this.num_joints > 0)
            System.arraycopy(this.joint_velocity_estimated, 0, outobj.joint_velocity_estimated, 0, this.num_joints); 
        outobj.joint_torque_measured = new double[(int) num_joints];
        if (this.num_joints > 0)
            System.arraycopy(this.joint_torque_measured, 0, outobj.joint_torque_measured, 0, this.num_joints); 
        outobj.joint_torque_commanded = new double[(int) num_joints];
        if (this.num_joints > 0)
            System.arraycopy(this.joint_torque_commanded, 0, outobj.joint_torque_commanded, 0, this.num_joints); 
        outobj.joint_torque_external = new double[(int) num_joints];
        if (this.num_joints > 0)
            System.arraycopy(this.joint_torque_external, 0, outobj.joint_torque_external, 0, this.num_joints); 
        return outobj;
    }
 
}
