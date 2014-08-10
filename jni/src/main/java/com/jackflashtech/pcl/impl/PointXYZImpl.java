package com.jackflashtech.pcl.impl;

import com.jackflashtech.pcl.*;

public class PointXYZImpl implements PointXYZ {

     private long handler = 0;

     public PointXYZImpl() {
          this(0.0f, 0.0f, 0.0f);
     }

     public PointXYZImpl(float x, float y, float z) {
          createPoint(x, y, z);
     }

     public PointXYZImpl(long handle) {
          handler = handle;
     }

     public synchronized native float getX();

     public synchronized native void setX(float x);

     public synchronized native float getY();

     public synchronized native void setY(float Y);

     public synchronized native float getZ();

     public synchronized native void setZ(float z);

     private synchronized native int createPoint(float x, float y, float z) throws UnsatisfiedLinkError;

     public native void finalize(); 
     //private synchronized static native int createPoint(float x, float y, float z) throws UnsatisfiedLinkError;
}
