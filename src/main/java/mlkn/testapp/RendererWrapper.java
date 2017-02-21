package mlkn.testapp;

// following tutorial: http://www.learnopengles.com/calling-opengl-from-android-using-the-ndk/

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;

public class RendererWrapper implements Renderer {
    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
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

// native version
/*
public class RendererWrapper implements Renderer {
    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        gl.glClearColor(0.9f, 0.1f, 0.1f, 1.0f);
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        // No-op
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        gl.glClear(gl.GL_COLOR_BUFFER_BIT);
    }
}
*/