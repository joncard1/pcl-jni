package com.jackflashtech.pcl;

import com.jackflashtech.pcl.impl.PointXYZImpl;

public class Main {
     public static void main(String[] args) throws Exception {
          System.loadLibrary("pcl_jni");
           
          PointXYZ pt1 = new PointXYZImpl();

          PointXYZ pt2 = new PointXYZImpl();
     }
}
