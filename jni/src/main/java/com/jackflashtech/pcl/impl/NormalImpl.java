package com.jackflashtech.pcl.impl;

import com.jackflashtech.pcl.Normal;

public class NormalImpl implements Normal {
	private long handle;

	public NormalImpl() {
		this(0f, 0f, 0f);
	}

	public NormalImpl(float x, float y, float z) {
		handle = createNormal(x, y, z);
	}

	private synchronized native long createNormal(float x, float y, float z);
}
