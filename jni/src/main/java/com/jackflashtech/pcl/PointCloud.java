package com.jackflashtech.pcl;

import java.util.List;

public interface PointCloud<E> {
	public int getHeight();
	public void setHeight(int height);
	public int getWidth();
	public void setWidth(int width);
	public boolean isDense();
	public void setIsDense(boolean isDense);
	public List<E> getPoints();
	public void resize();
}
