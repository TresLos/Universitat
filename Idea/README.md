Aquí proposo les meves propostes.

```
void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}


void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}
```

Però si ens fixem, son tots gairebé iguals.

```
void GLWidget::set$XYZ%Rotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != $xyz%Rot) {
        $xyz%Rot = angle;
        emit $xyz%RotationChanged(angle);
        updateGL();
    }
}
```

O propostes versimilars.
Ja que generar codi igual, sembla molt d'inutils...
