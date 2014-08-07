#include <com_jackflashtech_pcl_impl_NormalImpl.h>
#include <pcl/point_types.h>

JNIEXPORT jlong JNICALL Java_com_jackflashtech_pcl_impl_NormalImpl_createNormal (JNIEnv *env, jobject object, jfloat x, jfloat y, jfloat z) {
	pcl::Normal *new_normal = new pcl::Normal();
	new_normal->normal_x = x;
	new_normal->normal_y = y;
	new_normal->normal_z = z;

	return (jlong)new_normal;
}
