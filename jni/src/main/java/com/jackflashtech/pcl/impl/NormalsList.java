package com.jackflashtech.pcl.impl;

import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;
import java.util.ListIterator;
import java.util.Collection;
import com.jackflashtech.pcl.PointXYZ;

public class NormalsList<E> implements List<E> {

	private long handle;
	private List<E> internalList = new ArrayList<E>();

	public NormalsList(long handle) {
		this.handle = handle;	
	}

	public boolean add(E e) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}
	
	public void add(int index, E element) {
		add(handle, index, element);
		internalList.add(index, element);
	}

	private native synchronized void add(long handle, int index, E element);
	
	public boolean addAll(Collection<? extends E> c) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public boolean addAll(int index, Collection<? extends E> c) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public void clear() {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public boolean contains(Object c) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public boolean containsAll(Collection<?> c) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public boolean equals(Object c) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public E get(int index) {
		return get(index, handle);
	}

	private synchronized native E get(int index, long handle);

	public int hashCode() {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public int indexOf(Object c) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public boolean isEmpty() {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public Iterator<E> iterator() {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public int lastIndexOf(Object c) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public ListIterator<E> listIterator() {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public ListIterator<E> listIterator(int index) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public E remove(int index) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public boolean remove(Object c) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public boolean removeAll(Collection<?> c) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public boolean retainAll(Collection<?> c) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public E set(int index, E element) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public int size() {
		return size(this.handle);
	}

	private synchronized native int size(long handle);

	public List<E> subList(int fromIndex, int toIndex) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public Object[] toArray() {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}

	public <T> T[]	toArray(T[] a) {
		throw new UnsupportedOperationException("I haven't implemented this yet.");
	}
}
