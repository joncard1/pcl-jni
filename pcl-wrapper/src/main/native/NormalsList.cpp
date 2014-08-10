#include <iostream>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <com_jackflashtech_pcl_impl_NormalsList.h>

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_NormalsList_add (JNIEnv *env, jobject object, jlong handle, jint index, jobject element) {
	std::vector<pcl::Normal, Eigen::aligned_allocator<pcl::Normal> > *points = (std::vector<pcl::Normal, Eigen::aligned_allocator<pcl::Normal> > *)handle;

	// TODO: Check that the element is a PointXYZ;
	jfieldID l_handleId = env->GetFieldID( env->GetObjectClass( element ), "handle", "J");
	pcl::Normal *point = (pcl::Normal *)env->GetLongField(element, l_handleId);

	(*points)[index].normal_x = point->normal_x;
	(*points)[index].normal_y = point->normal_y;
	(*points)[index].normal_z = point->normal_z;
}

JNIEXPORT jobject JNICALL Java_com_jackflashtech_pcl_impl_NormalsList_get (JNIEnv *env, jobject object, jint index, jlong handle) {
	std::vector<pcl::Normal, Eigen::aligned_allocator<pcl::Normal> > *points = (std::vector<pcl::Normal, Eigen::aligned_allocator<pcl::Normal> > *)handle;
	pcl::Normal return_value = (*points)[index];

	jclass cls = env->FindClass("com/jackflashtech/pcl/impl/NormalImpl");
	jmethodID methodID = env->GetMethodID(cls, "<init>", "(J)V");
	jvalue args[1];
	args[0].j = (jlong)&((*points)[index]);
	jobject j_return_value;
	j_return_value = env->NewObjectA(cls, methodID, args);

	return j_return_value;
}


JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_NormalsList_size (JNIEnv *env, jobject object, jlong handle) {
	std::vector<pcl::Normal, Eigen::aligned_allocator<pcl::Normal> > *points = (std::vector<pcl::Normal, Eigen::aligned_allocator<pcl::Normal> > *)handle;
	return points->size();
}
