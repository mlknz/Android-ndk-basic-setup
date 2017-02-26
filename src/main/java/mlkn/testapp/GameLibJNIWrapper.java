package mlkn.testapp;

import android.content.res.AssetManager;

public class GameLibJNIWrapper {
    static {
        System.loadLibrary("appManager");
    }

    public static native void onSurfaceCreated();
    public static native void onSurfaceChanged(int width, int height);
    public static native void onDrawFrame();

    public static native void passAssetManager(AssetManager mgr);

    public static native void onTouchStart(float posX, float posY);
    public static native void onTouchMove(float posX, float posY);
    public static native void onTouchEnd(float posX, float posY);
}
