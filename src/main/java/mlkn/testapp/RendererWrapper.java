package mlkn.testapp;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.os.SystemClock;
import android.content.Context;
import android.opengl.GLSurfaceView.Renderer;

public class RendererWrapper implements Renderer {

    private final Context context;

    public RendererWrapper(Context context) {
        this.context = context;
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        GameLibJNIWrapper.passAssetManager(context.getAssets());
        // SystemClock.sleep(1000);
        GameLibJNIWrapper.onSurfaceCreated();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        GameLibJNIWrapper.onSurfaceChanged(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        GameLibJNIWrapper.onDrawFrame();
    }
}
