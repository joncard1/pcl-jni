package com.jackflashtech.pcl;

import com.jackflashtech.pcl.impl.PointXYZImpl;
import com.jackflashtech.pcl.impl.PointCloudPointXYZImpl;
import java.util.List;

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

          PointCloud cloud = new PointCloudPointXYZImpl(10, 20, false);
          System.out.println("Height: " + cloud.getHeight());
          System.out.println("Width: " + cloud.getWidth());
          System.out.println("Is Dense: " + cloud.isDense());

          cloud.setHeight(30);
          cloud.setWidth(40);
          cloud.setIsDense(true);
          System.out.println("Height: " + cloud.getHeight());
          System.out.println("Width: " + cloud.getWidth());
          System.out.println("Is Dense: " + cloud.isDense());

          System.out.println("Points: " + ( cloud.getPoints() == null ? "null" : "not null"));

          PointXYZ pt2 = new PointXYZImpl();
          pt2.setX(4.0f);
          pt2.setY(5.0f);
          pt2.setZ(6.0f);

          System.out.println("Hi");
          List points = cloud.getPoints();
          System.out.println("There");
          points.add(0, pt1);
          cloud.getPoints().add(1, pt2);

          System.out.println("Size: " + cloud.getPoints().size());


     }
}
