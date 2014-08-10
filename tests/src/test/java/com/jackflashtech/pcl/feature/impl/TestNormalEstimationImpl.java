package com.jackflashtech.pcl.features.impl;

import org.junit.Test;
import org.junit.Before;
import static org.junit.Assert.*;

import com.jackflashtech.pcl.features.NormalEstimation;
import com.jackflashtech.pcl.search.impl.KdTreePointXYZ;
import com.jackflashtech.pcl.PointCloud;
import com.jackflashtech.pcl.Normal;
import com.jackflashtech.pcl.PointXYZ;
import com.jackflashtech.pcl.impl.PointCloudPointXYZImpl;
import com.jackflashtech.pcl.impl.PointXYZImpl;
import com.jackflashtech.pcl.impl.PointCloudNormalImpl;
import java.sql.DriverManager;
import java.sql.Connection;
import java.util.Properties;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.List;

public class TestNormalEstimationImpl {
	@Before
	public void setUp() {
		System.loadLibrary("pcl-wrapper");
	}

	@Test
	public void testCreate() {
		NormalEstimation ne = new NormalEstimationImpl();
	}

	@Test
	public void testHighLoad() throws Exception {
          PointCloud cloud = new PointCloudPointXYZImpl();

	  Connection conn = null;
          Properties connectionProps = new Properties();
          connectionProps.put("user", "root");
          connectionProps.put("password", "Aeroty1a");

          conn = DriverManager.getConnection("jdbc:mysql://localhost/points", connectionProps);
          Statement stmt  = conn.createStatement();
          ResultSet rs = stmt.executeQuery("SELECT x, y, z, (SELECT COUNT(*) FROM points) total_rows FROM points;");
          cloud.setWidth(1);
          cloud.setIsDense(false);
          boolean first = true;
          int j = 0;
          while(rs.next()) {
               if(first) {
                    cloud.setHeight(rs.getInt(4));
                    cloud.setWidth(1);
                    cloud.resize();
                    first = false;
               }
               float x = rs.getFloat(1);
               float y = rs.getFloat(2);
               float z = rs.getFloat(3);
               cloud.getPoints().add(j, new PointXYZImpl(x, y, z));
               j++;
          }
          
          NormalEstimation ne = new NormalEstimationImpl();
          System.out.println("NormalEstimation created.");
          ne.setInputCloud(cloud);
          ne.setSearchMethod(new KdTreePointXYZ());
          ne.setRadiusSearch(5);
          System.out.println("Normal Estimation initialized.");

          PointCloud normal_cloud = new PointCloudNormalImpl();
          System.out.println("Output cloud created.");
          ne.compute(normal_cloud);
          System.out.println("Normals: " + ( normal_cloud.getPoints() == null ? "null" : "not null"));
          System.out.println("Normal cloud computed: " + normal_cloud.getPoints().size());

          List<Normal> normals = normal_cloud.getPoints();
          System.out.println("Got normals.");
          for(int i = 0; i < normals.size(); i++) {
               Normal normal = normals.get(i);
               System.out.println(i + ": X: " + normal.getX() + ", Y: " + normal.getY() + ", Z: " + normal.getZ());
          }
	
	}
}
