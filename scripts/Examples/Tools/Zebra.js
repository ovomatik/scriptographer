//////////////////////////////////////////////////////////////////////////////
// Values:

var values = {
	offset: 10,
	distance: 10,
	mouseOffset: false,
	speedScale: 1.5
};

//////////////////////////////////////////////////////////////////////////////
// Interface:

var components = {
	distance: {
		label: 'Spacing',
		onChange: function(value) {
			tool.minDistance = value;
		}
	},
	offset: {
		label: 'Size', type: 'number',
		range: [0, 500]
	},
	mouseOffset: {
		label: 'Dynamic size', type: 'checkbox',
		onChange: function(checked) {
			palette.components.offset.enabled = !checked;
		}
	}
};

var palette = new Palette('Zebra', components, values);

//////////////////////////////////////////////////////////////////////////////
// Mouse handling:

function onMouseDrag(event) {
	// the vector in the direction that the mouse moved:
	var step = event.delta.clone();
	
	if (!values.mouseOffset) {
		// normalize step to a specific length
		step.length = values.offset;
	}
	
	// find the middle point between the last and the current position
	var middle = event.point - event.delta / 2;	
	
	// the top point: the middle point + the step rotated by -90 degrees	
	var top = middle + step.rotate((-90).toRadians());

	// the bottom point: the middle point + the step rotated by 90 degrees	
	var bottom = middle + step.rotate((90).toRadians());
	
	//now create a line using the top and bottom points
	new Path.Line(top, bottom);
}