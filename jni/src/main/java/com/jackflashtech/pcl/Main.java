package com.jackflashtech.pcl;

import com.jackflashtech.pcl.impl.PointXYZImpl;

public class Main {
     public static void main(String[] args) throws Exception {
          System.out.println(System.getProperty("java.library.path"));
          System.loadLibrary("pcl-wrapper");
           
          PointXYZ pt1 = new PointXYZImpl();
          pt1.setX(1.0f);
          pt1.setY(2.0f);
          pt1.setZ(3.0f);
          System.out.println("X: " + pt1.getX());
          System.out.println("Y: " + pt1.getY());
          System.out.println("Z: " + pt1.getZ());

          PointXYZ pt2 = new PointXYZImpl();
     }
}
