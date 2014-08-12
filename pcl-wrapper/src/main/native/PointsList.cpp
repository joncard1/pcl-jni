#include <iostream>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <com_jackflashtech_pcl_impl_PointsList.h>

JNIEXPORT jlong JNICALL Java_com_jackflashtech_pcl_impl_PointsList_createList (JNIEnv *env, jobject object) {

        try {
                std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *new_list = new std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> >();

                return (jlong)new_list;
        } catch (std::bad_alloc& ba) {
                char *exClassName = "com/jackflashtech/pcl/PclException";
                jclass exClass = env->FindClass( exClassName );
                if( exClass == NULL ) {
                        exClass = env->FindClass( "java/lang/NoClassDefFoundError" );
                        return env->ThrowNew( exClass, "Could not find com.jackflashtech.pcl.PclException" );
                }

                return env->ThrowNew( exClass, "Bad allocation creating points list.");
        } catch (...) {
		char *exClassName = "com/jackflashtech/pcl/PclException";
		jclass exClass = env->FindClass( exClassName );
		if( exClass == NULL) {
			exClass = env->FindClass( "java/lang/NoClassDefFoundError" );
			return env->ThrowNew( exClass, "Could not find com.jackflashtech.pcl.PclException" );
		}

		return env->ThrowNew( exClass, "Unknown exception creating points list.");
	}
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointsList_add (JNIEnv *env, jobject object, jlong handle, jint index, jobject element) {
	std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *points = (std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *)handle;

	// TODO: Check that the element is a PointXYZ;
	jfieldID l_handlerId = env->GetFieldID( env->GetObjectClass( element ), "handler", "J");
	pcl::PointXYZ *point = (pcl::PointXYZ *)env->GetLongField(element, l_handlerId);
	
	(*points)[index].x = point->x;
	(*points)[index].y = point->y;
	(*points)[index].z = point->z;
}

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointsList_size (JNIEnv *env, jobject object, jlong handle) {
	std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *points = (std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *)handle;
	return points->size();
}

JNIEXPORT jobject JNICALL Java_com_jackflashtech_pcl_impl_PointsList_get (JNIEnv *env, jobject object, jint index, jlong handle) {
        std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *points = (std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *)handle;
        pcl::PointXYZ return_value = (*points)[index];

        jclass cls = env->FindClass("com/jackflashtech/pcl/impl/PointXYZImpl");
        jmethodID methodID = env->GetMethodID(cls, "<init>", "(J)V");
        jvalue args[1];
        args[0].j = (jlong)&((*points)[index]);
        jobject j_return_value;
        j_return_value = env->NewObjectA(cls, methodID, args);

        return j_return_value;
}

