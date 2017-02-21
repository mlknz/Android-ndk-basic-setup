package mlkn.testapp;

// following tutorial: http://www.learnopengles.com/calling-opengl-from-android-using-the-ndk/

public class GameLibJNIWrapper {
    static {
        System.loadLibrary("appManager");
    }

    public static native void onSurfaceCreated();

    public static native void onSurfaceChanged(int width, int height);

    public static native void onDrawFrame();
}
