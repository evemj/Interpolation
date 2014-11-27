#ifndef DoubleStyleInterpolation
#define DoubleStyleInterpolation

#include "core/animation/StyleInterpolation.h"

class DoubleStyleInterpolation : public StyleInterpolation{
public:
	static PassRefPtrWillBeRawPtr<DoubleStyleInterpolation> create(double* start, double* end, CSSPropertyID id,  ValueRange range);
	
	static bool canCreateFrom(const CSSValue&);
	
	virtual void apply(StyleResolverState&) const override;

    virtual void trace(Visitor*) override;

private: 
	DoubleStyleInterpolation(PassOwnPtrWillBeRawPtr<InterpolableValue> start, PassOwnPtrWillBeRawPtr<InterpolableValube> end, CSSPropertyID id, ValueRange range) : StyleInterpolation(start, end, id)
        , m_range(range)
    { }

    static PassOwnPtrWillBeRawPtr<InterpolableValue> doubleToInterpolableValue(double*);
    static PassRefPtrWillBeRawPtr<CSSValue> interpolableValueToDouble(InterpolableValue*, ValueRange);

    ValueRange m_range;

    friend class AnimationLengthStyleInterpolationTest;
};
#endif
