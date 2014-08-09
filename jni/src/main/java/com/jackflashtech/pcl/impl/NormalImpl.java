package com.jackflashtech.pcl.impl;

import com.jackflashtech.pcl.Normal;

public class NormalImpl implements Normal {
	private long handle;

	public NormalImpl() {
		this(0f, 0f, 0f);
	}

	public NormalImpl(float x, float y, float z) {
		this.handle = createNormal(x, y, z);
	}

	public NormalImpl(long handle) {
		this.handle = handle;
	}

	private synchronized native long createNormal(float x, float y, float z);

	public float getX() {
		return getX(handle);
	}

	private synchronized native float getX(long handle);

	public void setX(float x) {
		setX(x, handle);
	}

	private synchronized native void setX(float x, long handle);

	public float getY() {
		return getY(handle);
	}

	private synchronized native float getY(long handle);

	public void setY(float y) {
		setY(y, handle);
	}

	private synchronized native void setY(float y, long handle);

	public float getZ() {
		return getZ(handle);
	}

	private synchronized native float getZ(long handle);

	public void setZ(float z) {
		setZ(z, handle);
	}

	private synchronized native void setZ(float z, long handle);

	public void finalize() {
		finalize(handle);
	}

	private synchronized native void finalize(long handle);
}
